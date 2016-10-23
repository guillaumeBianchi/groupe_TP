<html>
    <head><title>Exercice 4</title>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	</head>
    <body>
		<?php

class Calcul {

    private $nbr1;
    private $nbr2;


	function __construct ()
	{
		$this->nbr1 = $_POST['nombre1'];
		$this->nbr2 = $_POST['nombre2'];
	}
	
	/*function __destruct() {
        echo "destruction de l'objet";
    }*/

    function addition() {
		$res = $this->nbr1 + $this->nbr2;
		echo $this->nbr1." + ".$this->nbr2." = ".$res; 
    }
	
	function soustraction() {

		$res = $this->nbr1 - $this->nbr2;
		echo $this->nbr1." - ".$this->nbr2." = ".$res; 

    }
	
	function multiplication() {

 		$res = $this->nbr1 * $this->nbr2;
		echo $this->nbr1." * ".$this->nbr2." = ".$res; 

    }
	
    function division() {

		$res = $this->nbr1 / $this->nbr2;
		echo $this->nbr1." / ".$this->nbr2." = ".$res; 

    }	

}

		$a = $_POST['nombre1'];
		$b = $_POST['nombre2'];

		{
			echo "Calcul arithmetique a base de classe";
			echo "<br/>";
			if ( is_numeric($_POST['nombre1']) && is_numeric($_POST['nombre2']) )
			{
				
				$op=$_POST['operation'];
				$objet = new Calcul;
				switch ($op)
				{
					case 'add':
					$objet->addition();
					break;
					
					case 'sous':
					$objet->soustraction();
					break;
					
					case 'mult':
					$objet->multiplication();
					break;
					
					case 'divi':
					$objet->division();
					break;
				}
			}
			else
			{
				echo "Erreur dans les données";
				?>
				<br/>
				<a href="ex4.php">Entrer à nouveau les données</a>
				<?php
			}
			
		}

		?>

    </body>
</html>		
		