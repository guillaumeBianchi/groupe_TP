<html>
    <head><title>Exercice 8</title>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	</head>
    <body>
        <form name="formulaire" method="post" action= ex8.php >
		Champs en <b>gras</b> sont requis
		 <br/>
		 
        <b>Nom :</b> <input type="text" name="nom" required/> <br/>
        <b>Sujet :</b> <input type="text" name="sujet"required/><br/>
		<b>Email :</b><input type="text" name="email"required/><br/>
		Site web : <input type="text" name="adresse"/><br/>	
		
		<label for="choix">Aimez-vous ce site ? </label>
		<INPUT type= "radio" name="choix" value="oui"> Oui 
		<INPUT type= "radio" name="choix" value="non"> Non <br/>
		
		<label for="site">Comment avez-vous retrouvé ce site ?</label>
		<SELECT name="site" id="site" size="1">
		<OPTION selected>-- Selectionner --
		<OPTION value="google">Google
		<OPTION value="yahoo">Yahoo
		<OPTION value="lien">Lien d'un autre site
		<OPTION value="bouche">De bouche à oreille
		<OPTION value="autre">Autre		
		</SELECT> 
		
		 <br/>
		<label for="com"><b>Votre commentaire : </b></label> <br/>
		<TEXTAREA name="com" rows=10 cols=50 placeholder = "Votre commentaire"required></TEXTAREA>
		 <br/>
		
		<input type="submit" name="valider" value="Envoyer !"/> 
        </form>

    </body>
</html>