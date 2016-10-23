<html>
    <head><title>Exercice 1</title>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />	
	</head>
    <body>
		<?php
		function factorielle($nombre) 
		{ 
		   if($nombre === 0) // condition d'arret 
			  return 1;  
		  else 
			  return $nombre*factorielle($nombre-1); 
		} 
		for($i = 0; $i < 11 ; $i++)
		{
			$tab[] = factorielle($i);
		}
		
        ?>
		
	<TABLE BORDER="1"> 
	  <CAPTION> Calcul des factorielles en utilisant la récursivité </CAPTION> 
	  <TR> 
	 <TH> Entier </TH> 
	 <TH> Factorielle </TH> 
	  </TR> 
	  <?php
	  foreach ($tab as $key => $value)
	  {
	  ?>
	  <TR> 
	 <TH> <?php echo $key; ?> </TH> 
	 <TD> <?php echo $value;?>  </TD> 
	  </TR>
	  <?php
	  }
	  ?>

	</TABLE> 
		
    </body>
</html>
		
