import urllib.request
from bs4 import BeautifulSoup


class Scraper:
    def __init__(self, site):
        self.site = site

    def scrape(self):
        response = urllib.request.urlopen(self.site)
        html = response.read()
        soup = BeautifulSoup(html, 'html.parser')
        with open("output.txt", "w") as f:
            for tag in soup.find_all('a'):
                url = tag.get('href')
                #print(url)
                if url and 'youtube' in url:
                    print("\n" + url)
                    f.write(url + "\n")

Scraper('https://www.uvic.ca/').scrape()