import requests
import re

raw_url = 'https://viewdns.info/reverseip/?host=' + input('Site: ') + '&t=1'
url = raw_url

links_reads = set()

header = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.135 Safari/537.36', 
          'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9', 
          'Accept-Language': 'pt-BR,pt;q=0.9,en-US;q=0.8,en;q=0.7'}


req = requests.get(url, headers=header)
html = req.text
print(html)
links = re.findall(r'[<td>]\w+globo?\.com?', html) + re.findall(r'[<td>]\w+\.globo', html)
for link in links:
    if link not in links_reads:
        links_reads.add(link)

print(links_reads)