import requests

if __name__ == "__main__":
    grit_page = requests.get("http://www.umbc.edu").text
    print(grit_page)
    length = grit_page.split("</a>")
    
    print("There are: " + str(len(length)) + " links")
