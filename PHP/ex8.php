<html>
    <head><title>Exercice 8</title>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	</head>
    <body>
		<?php
	
		$email=$_POST['email'];
		$expreg = "#^[a-z]*@[a-z]*\.[a-z]{2,4}$#";
		
		if ( preg_match($expreg, $email) )
			{
				?>
				<b>Votre message a été envoyé avec succès !</b> <br/>
				Merci de votre participation.
				<?php
			}
			
			else
			{
				echo "<h1> L'adresse mail n'est pas valide !!</h1>";
				require("td8.php");
			}
			
	?>

    </body>
</html>		
		