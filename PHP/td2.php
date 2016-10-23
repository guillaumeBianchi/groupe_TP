<html>
    <head><title>Exercice 2</title>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" /></head>
    <body>
		<?php

		$villes = array (
			'France' => ['Paris' ,'Lyon','Marseille', 'Nantes', 'Lille'],
			'Allemagne' => ['Berlin', 'Hambourg','Hanovre','Munich', 'Cologne'],
			'Espagne' => ['Madrid','Bilbao', 'Grenade', 'Barcelone', 'Séville']
			);
		  
		?>
		
<TABLE BORDER="1"> 
  <CAPTION> Villes par pays </CAPTION> 

  <?php 
  foreach($villes as $key=>$value) {
	  ?>
    <TR> 
 <TH> <?php echo $key ?>  </TH> 
	<?php
	  foreach($value as $data){
  ?>
 <TH> <?php echo $data ?> </TH> 
 
  <?php
  }
  ?>
   </TR>
 <?php   
  }
  ?>

  </TABLE>
    </body>
</html>		
		