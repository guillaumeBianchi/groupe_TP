<?php 
		
		$choix = $_POST['site'];
		switch($choix)
		{
			case "fr":
			echo ' <meta http-equiv="refresh" content="1;url=http://google.fr"/> ';
			break;
			
			case "es":
			echo ' <meta http-equiv="refresh" content="1;url=http://google.es"/> ';
			break;
			
			case "uk":
			echo ' <meta http-equiv="refresh" content="1;url=http://google.co.uk"/> ';
			break;
		}
		
?>