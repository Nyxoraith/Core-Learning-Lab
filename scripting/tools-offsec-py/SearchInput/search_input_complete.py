import requests
import re

to_crawl = ['http://globo.com/'] #EDITAR
raw_url = 'https://viewdns.info/reverseip/?host=' + raw_input("Domain's: ") + '&t=1'
url = raw_url
print url
crawled = set()
encontrados = set()
links_reads = set()

header = {'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) '
                        'AppleWebKit/537.36 (KHTML, like Gecko) '
                        'Chrome/51.0.2704.103 Safari/537.36',
          'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9', 
          'Accept-Language': 'pt-BR,pt;q=0.9,en-US;q=0.8,en;q=0.7'}

def main():
    ### WEB CRAWLING ###
    while True :
        url = to_crawl[0]
        try:
            req = requests.get(url, headers=header)
        except:
            to_crawl.remove(url)
            crawled.add(url)
            continue

        html = req.text
        links = re.findall(r'<a href="?\'?(https?:\/\/[^"\'>]*)', html)
        
        to_crawl.remove(url)
        crawled.add(url)

        for link in links:
            if link not in crawled and link not in to_crawl:
                to_crawl.append(link)

        ### ENCONTRAR PARAMETROS INPUT NO SOURCE CODE ###
                
        entradas = re.findall(r'<input', html)
        if not entradas:
            continue
        else:
            print "OK:" , url

        for entrada in entradas:
            if entrada not in encontrados:
                encontrados.add(url)

def get():
    req = requests.get(url, headers=header)
    html = req.text
    links = re.findall(r'[<td>]\w+globo?\.com?', html) + re.findall(r'[<td>]\w+\.globo', html) #Editar
    for link in links:
        if link not in links_reads:
            links_reads.add(link)
    #print links_reads


get()
main()