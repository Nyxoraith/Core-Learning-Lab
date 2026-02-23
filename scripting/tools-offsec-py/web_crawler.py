import requests
import re

to_crawl = ['http://www.aboutyou.es']
crawled = set()

header = {'user-agent': 'Mozilla/5.0 (Hackerone/Severost) '}

while True:
    url = to_crawl[0]
    try:
        req = requests.get(url, headers=header)
    except:
        to_crawl.remove(url)
        crawled.add(url)
        continue

    html = req.text
    links = re.findall(r'<a href="?\'?(https?:\/\/[^"\'>]*)', html)
    print('Crawling:', url)

    to_crawl.remove(url)
    crawled.add(url)

    for link in links:
        if link not in crawled and link not in to_crawl:
            to_crawl.append(link)