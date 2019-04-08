import sys
from twilio.rest import Client

# Declare all variables needed to send the message
expert_phone = "+506"
sender_phone = ""
account_SID = ""
auth_token = ""

# Get a file a extract information
f = open("../TextFiles/config.properties","r")
if f.mode == 'r':
    contents = f.read()
    info = contents.splitlines()
    prop_file = info[1].split("=")
    expert_phone = expert_phone+(prop_file[1])
    prop_file = info[2].split("=")
    sender_phone = (prop_file[1])
    prop_file = info[3].split("=")
    account_SID = (prop_file[1])
    prop_file = info[4].split("=")
    auth_token = (prop_file[1])

    print(expert_phone, sender_phone, account_SID,auth_token)

# Oscar info
#client = Client("ACa6685a97452f0ece836abc03716db0af", "f3c0fdf02e108eb6acc88dd85900e99e")

# Esteban info
client = Client(account_SID,auth_token)
client.messages.create(to=expert_phone,from_=sender_phone,
body="Atencion experto en palabras! La palabra <" + sys.argv[1] + "> quiere ser incluida al diccionario de juego, seleccione SI o NO en la aplicacion del experto para proceder con la partida.")

#to="+50660694075", from_="+12027596195",
