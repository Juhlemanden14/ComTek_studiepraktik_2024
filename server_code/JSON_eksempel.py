"""
Dette script indeholder et eksempel på at arbejde med JSON formattet i Python.
Det kan I bruge til at modtage data fra jeres IoT device.
"""

import json

# python dictionary - se det som en ordbog, man slår op med et indeks/ord, får en beskrivelse/hvad der indeholdes ved det indeks/ord
my_dict = {       
    "pakke_info": [0, 2],       # kunne være IoT device ID (0) og datapunkter i pakken (2)
    "payload": [62.5, 23.0]     # luftfugt [%] og temperatur [celsius]
}

# print/vis i terminalen
print("Print af my_dict: ", end="")
print(my_dict)

my_json = json.dumps(my_dict)

# når man printer JSON objektet, ser forskellen meget lille ud - dictionaries og JSON minder nemlig om hinanden.
# Det snyder dog, da my_json er en string, som man kan ikke let hente dataen ud igen. Dog ville man kunne sende my_json til IoT devicen
# og hvis den læser det som JSON, er de enige om hvad der står! Det er det fede ved formatter som JSON.
print("Print af my_json: ", end="")
print(my_json)
print(f"my_json type: {type(my_json)}")

# læs data fra JSON objekt
læst_json = json.loads(my_json)

# indeksering i JSON objektet - læs hvad der står ved 'pakke_info' nøglen (key/value pair)
pakke_info = læst_json["pakke_info"]
print("Print af pakke_info: ", end="")
print(pakke_info)