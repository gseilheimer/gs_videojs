
<?php
/**
 *=======================================================
 * Modul: Bild (Format + Layout (jquery))
 * Bereich: Ausgabe
 * Version: 1.5
 * Redaxo Version: 4.3
 * Redaxo AddOns: Image Manager & FancyBox
 * Erstellung: Eilige-EDV, G. Seilheimer
 * Datum: 2010-04-30
 *=======================================================
 */
	
	// VARS
	$error_text 				= "<span style='color: red'>HINWEIS: </span>";
	$ok_img						= true;
	$ok_txt						= true;
	$ok_img_error				= "Bild fehlt...!<br />";
	$ok_txt_error				= "Text fehlt...!<br />";
	
	// VARS - Bild - Pfad
	$rex_img 					= "REX_MEDIA[1]"; 				//bild pfad	
	// VARS - Bild - Align, Size
	$rex_img_size				= "REX_VALUE[2]";				//bild groesse
	$rex_img_align				= "REX_VALUE[3]";				//bild ausrichtung
	$rex_img_brand				= "REX_VALUE[4]";				//bild branding in resize und fancybox (brand.gif)
	#$rex_img_shuffle			= "REX_VALUE[5]";				//bild shuffle-modus		
	// VARS - Bild - Title
	$rex_img_txt_display		= "REX_VALUE[6]";				//bild text on/off
	$rex_img_txt				= "REX_VALUE[7]";				//bild text
	$rex_img_txt_position		= "REX_VALUE[8]";				//bild text oben/unten	
	// VARS - Bild - JQuery
	$rex_img_js					= "REX_VALUE[11]";				//bild js window aktiv	
	$rex_img_js_style			= "REX_VALUE[12]";				//bild js window style		
	$rex_img_size_window		= "REX_VALUE[13]";				//bild groesse window
	// VARS - Link - JQuery
	$rex_link_intern			= "REX_LINK[1]"; 				//artikel pfad
	$rex_link_extern			= "REX_VALUE[16]"; 				//link extern pfad

	
	// CHECK - Image
	if("" == $rex_img)
	{
		$ok_img	= false;
	}
	
	// CHECK - Image-Description
	if("" == $rex_img_txt)
	{
		$ok_txt	= false;
	}
	
	// CHECK - Image-Branding
	if("Brand-On" === $rex_img_brand)
	{
		$rex_img_brand	= "&rex_filter[]=brand";
	}
	else
	{
		$rex_img_brand	= "";
	}	
	
	// CHECK - Floating
	if("links" === $rex_img_align)
	{
		$style_float	= "style=\"float: left; padding: 0.5em 1em 0.5em 1em;\"";
	}
	elseif("rechts" === $rex_img_align)
	{
		$style_float	= "style=\"float: right; padding: 0.5em 1em 0.5em 1em;\"";
	}
	else
	{
		$style_float	= "style=\"float: none; padding: 0.5em 1em 0.5em 1em;\"";
	}	

	// VARS	
	$divclass_img			= "<span {$style_float}>";				//innen
	$divclass_img_end		= "</span>";							//innen end

	if(true == $REX['REDAXO'])
	{	//Ausgabe im Backend
	
		if(false == $ok_img)
		{
			echo $error_text . $ok_img_error;
		}
		
		if(false == $ok_txt)
		{
			echo $error_text . $ok_txt_error;
		}
		
		if("" != $rex_img)
		{			
			if( "" == trim($rex_img_txt) )
			{
				// Bildtitel auslesen
		    	if ($rex_img_tmp = OOMedia::getMediaByFileName($rex_img))
				{
					$rex_img_txt = $rex_img_tmp->getTitle();
				}
				else
				{
					$rex_img_txt = $rex_img;
				}
			}	
					
			echo "<a href=\"{$REX['HTDOCS_PATH']}/files/{$rex_img}\" rel=\"group-REX_ARTICLE_ID-REX_SLICE_ID\">";
			echo "<img src=\"{$REX['HTDOCS_PATH']}index.php?rex_resize=200a__{$rex_img}{$rex_img_brand}\" 
					title=\"{$rex_img_txt}\" alt=\"{$rex_img}\" />";
			echo "</a>";
						
			echo "<br />{$rex_img_txt}<br />";
		}
		
	}	//Ausgabe im Backend - ENDE
	else
	{	//Ausgabe im Frontend
		
		if("" != $rex_img)
		{			
			if( "" == trim($rex_img_txt) )
			{
				// Bildtitel auslesen
		    	if ($rex_img_tmp = OOMedia::getMediaByFileName($rex_img))
				{
					$rex_img_txt = $rex_img_tmp->getTitle();
				}
				else
				{
					$rex_img_txt = $rex_img;
				}
			}
						
	    	echo "{$divclass_img}";				//Start - Image - DIV
	    	
			if("Alt-Title-On" === $rex_img_txt_display)
			{	// Alt-Title-On
				if("Alt-Title-Top" === $rex_img_txt_position)
				{
					echo "{$rex_img_txt}<br />";
				}
				
				if("JS-On" == $rex_img_js)
				{	// JS aktiviert		
					if("" == $rex_link_extern)
					{
						echo "<a href=\"{$REX['HTDOCS_PATH']}index.php?rex_resize={$rex_img_size_window}a__{$rex_img}{$rex_img_brand}\" 
								rel=\"group-REX_ARTICLE_ID-REX_SLICE_ID\" class=\"fancyboxStyle{$rex_img_js_style}\">";
					}
					else
					{
						echo "<a href=\"{$rex_link_extern}\" 
								rel=\"group-REX_ARTICLE_ID-REX_SLICE_ID\" class=\"fancyboxStyle{$rex_img_js_style} iframe\">";

					}

					echo "<img src=\"{$REX['HTDOCS_PATH']}index.php?rex_resize={$rex_img_size}a__{$rex_img}{$rex_img_brand}\" 
							title=\"{$rex_img_txt}\" alt=\"{$rex_img}\" />";
					echo "</a>";							
				}
				else
				{	// JS deaktiviert
		    		echo "<img src=\"{$REX['HTDOCS_PATH']}index.php?rex_resize={$rex_img_size}a__{$rex_img}{$rex_img_brand}\" 
		    					title=\"{$rex_img_txt}\" alt=\"{$rex_img_txt} | {$rex_img}\" />";				
				}
				
				if("Alt-Title-Bottom" === $rex_img_txt_position)
				{
					echo "<br />{$rex_img_txt}";
				}
			}
			else
			{
				if("JS-On" == $rex_img_js)
				{	// JS aktiviert		
					if("" == $rex_link_extern)
					{
						echo "<a href=\"{$REX['HTDOCS_PATH']}index.php?rex_resize={$rex_img_size_window}a__{$rex_img}{$rex_img_brand}\" 
								rel=\"group-REX_ARTICLE_ID-REX_SLICE_ID\" class=\"fancyboxStyle{$rex_img_js_style}\">";
					}
					else
					{
						echo "<a href=\"{$rex_link_extern}\" 
								rel=\"group-REX_ARTICLE_ID-REX_SLICE_ID\" class=\"fancyboxStyle{$rex_img_js_style} iframe\">";

					}

					echo "<img src=\"{$REX['HTDOCS_PATH']}index.php?rex_resize={$rex_img_size}a__{$rex_img}{$rex_img_brand}\" 
							title=\"{$rex_img_txt}\" alt=\"{$rex_img_txt} | {$rex_img}\" />";
					echo "</a>";				
				}
				else
				{	// JS deaktiviert
		    		echo "<img src=\"{$REX['HTDOCS_PATH']}index.php?rex_resize={$rex_img_size}a__{$rex_img}{$rex_img_brand}\" 
		    				title=\"{$rex_img_txt}\" alt=\"{$rex_img}\" />";				
				}
			}
		    
			echo "{$divclass_img_end}";			//Start - Image - DIV
		}
	}
?>
