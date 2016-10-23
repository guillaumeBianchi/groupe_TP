<html>
    <head><title>Exercice 7</title>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />	
	</head>
    <body>
		<?php
		$expreg = "#^\d*\.\d*\seur$#";
		$test = $_POST['montant'];
		if ( preg_match($expreg, $test) )
		{
			echo "Le montant de la transaction est :".$test;
			echo "<br/>";
			echo "Le montant de la transaction est : [CONFIDENTIEL]";
			
		}
		else
		{
			echo "Erreur";
			?>
			<br/>
			<a href="ex7.php">Entrer à nouveau les données</a>
			<?php
		}
        ?>


    </body>
</html>
		
