import cgi
import urllib.request

form = cgi.FieldStorage()

print("Content-type: text/html; charset=utf-8\n")

html="""<!DOCTYPE html>
<head>
    <title> TD Vertica </title>
</head>
<body>
<h2>Query Text Index</h2>
    <form action="/querytextindex.py" method="post">
        Mot a rechercher: <input type="text" name="word" value="Query text" /><br/>
        Nom de l'index: <input type="text" name="nom_index" value="Nom de l'index" /><br/>
        Api key: <input type="text" name="api_key" value="api key" /><br/>
        <input type="submit" name="send" value="Add To Text Index"><br/>
    </form>
</body>
</html>
"""

text=form.getvalue("word")
nom_index=form.getvalue("nom_index")
api_key=form.getvalue("api_key")
if (form.getvalue("site")) or (form.getvalue("nom_index")) or (form.getvalue("api_key")):
    with urllib.request.urlopen("https://api.havenondemand.com/1/api/sync/querytextindex/v1?text="+text+"&ignore_operators=false&indexes="+nom_index+"&promotion=false&total_results=false&apikey="+api_key) as response:
        test = response.read()
    print("Le resultat de la requête est:")
    print("<br/>",test)
else:
    print("Un ou plusieurs champs manquants !")

print(html)
