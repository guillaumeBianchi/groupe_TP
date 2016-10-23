<html>
    <head><title>Exercice 6</title>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />	
	</head>
    <body>
		<?php
			$duree = 60*60;
			$timer = time()+$duree;

			if ( (empty($_COOKIE['d'])) )
			{
				echo "Bonjour, c'est la premiere visite de cette page. Soyez les bienvenus!";
				echo "<br/>";
				setcookie("d", $timer, $timer);
			}
			else
			{
				$ex = (gmdate("U",$_COOKIE['d']) - time());
				$min = floor(($duree - $ex)/60);
				$sec = ($duree - $ex) - $min*60;
				if($min==0 && $sec==1)
				{
					echo "Bonjour. Vous avez crée cette page il y a ".$sec." seconde";
				}
				else if ($min==0 && $sec>1)
				echo "Bonjour. Vous avez crée cette page il y a ".$sec." secondes";
				else if ($min==1 && $sec==1)
				echo "Bonjour. Vous avez crée cette page il y a ".$min." minute et ".$sec." seconde";
				else if ($min==1 && $sec>1)
				echo "Bonjour. Vous avez crée cette page il y a ".$min." minute et ".$sec." secondes";
				else if ($min>1 && $sec==1)
				echo "Bonjour. Vous avez crée cette page il y a ".$min." minutes et ".$sec." seconde";	
				else if ($min>1 && $sec>1)
			echo "Bonjour. Vous avez crée cette page il y a ".$min." minutes et ".$sec." secondes";
			}	
		?>

    </body>
</html>		
		