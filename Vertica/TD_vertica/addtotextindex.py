import cgi
import urllib.request

form = cgi.FieldStorage()

print("Content-type: text/html; charset=utf-8\n")

html="""<!DOCTYPE html>
<head>
    <title> TD Vertica </title>
</head>
<body>
<h2>Add to Text Index</h2>
    <form action="/addtotextindex.py" method="post">
        Nom du site: <input type="text" name="site" value="URL" /><br/>
        Nom de l'index: <input type="text" name="nom_index" value="Nom de l'index" /><br/>
        Api key: <input type="text" name="api_key" value="api key" /><br/>
        <input type="submit" name="send" value="Add To Text Index"><br/>
    </form>
</body>
</html>
"""

site=form.getvalue("site")
nom_index=form.getvalue("nom_index")
api_key=form.getvalue("api_key")
if (form.getvalue("site")) or (form.getvalue("nom_index")) or (form.getvalue("api_key")):
    with urllib.request.urlopen("https://api.havenondemand.com/1/api/sync/addtotextindex/v1?url="+site+"&index="+nom_index+"&apikey="+api_key) as response:
        test = response.read()
    print("Le resultat de la requete est:")
    print("<br/>",test)
else:
    print("Un ou plusieurs champs manquants !")

print(html)
