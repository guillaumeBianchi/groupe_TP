<html>
    <head><title>Exercice 3</title></head>
    <body>
		<?php
			echo 'Bonjour !';
			echo "<br/>";
			date_default_timezone_set("Europe/Paris");
			setlocale (LC_TIME, 'fr_FR.UTF8','fra');
			$date = strftime('%A %d/%m/%Y');
			$heure = strftime('%H:%M:%S');
			echo "Aujourd'hui c'est le ".$date;
			echo "<br/>";
			echo "\n Il est ".$heure;		
		?>

    </body>
</html>		
		