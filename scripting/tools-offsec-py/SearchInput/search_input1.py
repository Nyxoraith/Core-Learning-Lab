import requests
import re

encontrados = set()
numbers = 0
header = {'user-agent': 'Mozilla/5.0 (Hackerone/Severost'}
url = 'https://www.aboutyou.es'
req = requests.get(url, headers=header)
html = req.text
entradas = re.findall(r'<input', html)
for entrada in entradas:
    if entrada not in encontrados:
            encontrados.add(entrada)
            numbers += 1
print("Nesta pagina contem: ", numbers, " input(s).")