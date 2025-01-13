import argparse
import requests
import json
import datetime

def analyser_commande():
    parser = argparse.ArgumentParser(
        description="Extraction de valeurs historiques pour un ou plusieurs symboles boursiers.")
    parser.add_argument('symboles', nargs='+', help="Nom d'un symbole boursier")
    parser.add_argument('-d', '--début', metavar='DATE',
                        type=str, help="Date recherchée la plus ancienne (format: AAAA-MM-JJ)")
    parser.add_argument('-f', '--fin', metavar='DATE',
                        type=str, default=f'{datetime.date.today()}',
                        help="Date recherchée la plus récente (format: AAAA-MM-JJ)")
    parser.add_argument('-v', '--valeur', metavar='{fermeture,ouverture,min,max,volume}',
                        default="fermeture", help="La valeur désirée (par défault: fermeture)")
    return parser.parse_args()

def produire_historique(symbole, début, fin, valeur):
    url = f'https://pax.ulaval.ca/action/{symbole}/historique/'

    params = {
        'début': début,
        'fin': fin
    }

    try:
        réponse = requests.get(url=url, params=params, timeout=10)
        réponse.raise_for_status()  # Check for HTTP errors
        réponse = json.loads(réponse.text)
    except requests.exceptions.RequestException as e:
        print(f"Error making HTTP request: {e}")
        return []

    date_verifie = sorted(réponse.get('historique', {}).keys())
    liste_date = []

    for dates in date_verifie:
        try:
            d_object = datetime.date.fromisoformat(dates)
            liste_date.append(
                (datetime.date(d_object.year, d_object.month, d_object.day), réponse["historique"][dates][valeur]))
        except ValueError as ve:
            print(f"Error parsing date {dates}: {ve}")

    return liste_date

def afficher_résultats(symbole, valeur, début, fin, résultats):
    titre = f"{symbole}: valeur={valeur}, début={début}, fin={fin}"
    print(f"titre={titre}\n{résultats}")

if __name__ == "__main__":
    args = analyser_commande()

    if args.début is None:
        args.début = args.fin

    for symbole in args.symboles:
        résultats = produire_historique(symbole, args.début, args.fin, args.valeur)
        afficher_résultats(symbole, args.valeur, args.début, args.fin, résultats)
