import requests
import re

to_crawl = [ input("Site: ") ]
crawled = set()
encontrados = set()

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
        links = re.findall(r'<a href="?\'?(https?:\/\/[^"\'>]*)?', html)
        
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
            print ("OK:" , url)
        for entrada in entradas:
            if entrada not in encontrados:
                encontrados.add(url)

main()