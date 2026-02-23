import requests 

url_zero = 'http://www.bancocn.com'

wordlist = open('common.txt', 'r')

for linha in wordlist:
    url = url_zero + '/' + linha
    req = requests.get(url)
    if(req.status_code != 404):
        print("Encontramos algo: ", url, req.status_code)