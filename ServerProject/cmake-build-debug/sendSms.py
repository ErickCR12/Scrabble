import sys
from twilio.rest import Client

client = Client("ACa6685a97452f0ece836abc03716db0af", "f3c0fdf02e108eb6acc88dd85900e99e")

client.messages.create(to="+50660694075", 
                       from_="+12027596195", 
                       body="Atencion experto en palabras! La palabra " + sys.argv[1] + " quiere ser incluida al diccionario de juego, seleccione SI o NO en la aplicacion del experto para proceder con la partida.")
