print("Content-type: text/html; charset=utf-8\n")

html="""<!DOCTYPE html>
<head>
    <title> TD Vertica </title>
</head>
<body>
    <form action="/addtotextindex.py" method="post">
        <input type="submit" name="send" value="Add To Text Index"><br/>
    </form>
    <form action="/querytextindex.py" method="post">
        <input type="submit" name="send" value="Query Text Index"><br/>
    </form>
</body>
</html>
"""

print(html)
