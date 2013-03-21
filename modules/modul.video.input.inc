<?php
/**
 *=======================================================
 * Modul: Bild (Format + Layout (jquery))
 * Bereich: Eingabe
 * Version: 1.5
 * Redaxo Version: 4.3
 * Redaxo AddOns: Image Manager & FancyBox
 * Erstellung: Eilige-EDV, G. Seilheimer
 * Datum: 2010-04-30
 *=======================================================
 */

	if( OOAddon::isAvailable('image_resize') || OOAddon::isAvailable('image_manager') && OOAddon::isAvailable('fancybox') ) 
	{
?>			
		<script type="text/javascript"> 
		$(document).ready(function(){
			
			$(".toggle_container").hide();
			$("h2.trigger:first").addClass("active");
			$(".toggle_container:first").slideToggle("slow,");			
		 
			$("h2.trigger").toggle(function(){
				$(this).addClass("active"); 
				}, function () {
				$(this).removeClass("active");
			});
			
			$("h2.trigger").click(function(){
				$(this).next(".toggle_container").slideToggle("slow,");
			});
		 
		});
		</script>

		<style type="text/css">
		<!--			
			/* start - div */
			.container {
				width: 700px;
				margin: 0 auto;
			}
			h2.trigger {
				padding: 0 0 0 20px;
				margin: 0 0 5px 0;
				background: #3C9ED0;
				height: 46px;
				line-height: 46px;
				width: 680px;
				font-size: 1.5em;
				font-weight: normal;
				float: left;
			}
			h2.trigger a {
				color: #fff;
				text-decoration: none;
				display: block;
			}
			h2.trigger a:hover {
				color: #ccc;
			}
			h2.active {
				background: #14568a;
			}
			.toggle_container {
				margin: 0 0 5px;
				padding: 0;
				border-top: 1px solid #d6d6d6;
				background: #f0f0f0;
				overflow: hidden;
				font-size: 1.0em;
				line-height: 1.5em;
				width: 700px;
				clear: both;
			}
			.toggle_container .block {
				padding: 20px;
				background: ;
			}
			.toggle_container .block p {
				padding: 5px 0;
				margin: 5px 0;
			}
			.toggle_container h3 {
				font: 1.5em normal Georgia, "Times New Roman", Times, serif;
				margin: 0 0 10px;
				padding: 0 0 5px 0;
				border-bottom: 1px dashed #ccc;
			}
			.toggle_container img {
				float: left;
				margin: 10px 15px 15px 0;
				padding: 5px;
				background: #ddd;
				border: 1px solid #ccc;
			}				
			/* end - div */ 
		-->
		</style>

		<div class="container">

			<h2 class="trigger"><a href="#">IMAGE (Basics) (An/Aus)</a></h2>
			<div class="toggle_container">
				<div class="block">
				<h3>Bild (Vorschau)</h3>
	            <?php
	            $rex_img = "REX_MEDIA[1]";
				
	            if ("" != $rex_img) 
				{ 	// Bildtitel auslesen
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
					//Bildvorschau
					echo "<img src=\"{$REX['HTDOCS_PATH']}/index.php?rex_resize=150a__{$rex_img}\" />";
					echo "<p>Bildtext: {$rex_img_txt} <br />Bildname: {$rex_img}</p>";
	            }
				else
				{
					$rex_img = "no_image.gif";
					echo "<img src=\"{$REX['HTDOCS_PATH']}/index.php?rex_resize=150a__{$rex_img}\">";
					echo "<p>Bildtext: {$rex_img_txt} <br />Bildname: {$rex_img}</p>";
				}
	            ?>
	            
	            <h3>Bild (Auswahl)</h3>
				<p>
					REX_MEDIA_BUTTON[1]
				</p>				            

				<h3>Bildgröße (in Pixel)</h3>
				<p>
		            <select name="VALUE[2]" id="VALUE[2]">
		                <?php
		                foreach (array("50", "75", "100", "150", "200", "250", "300", "450", "600", "800") as $value) {
		                    echo '<option value="'.$value.'" ';
		                    
		                    if ("REX_VALUE[2]" == "$value") {
		                        echo 'selected="selected" ';
		                    }
		                    
		                    echo '>'.$value.'</option>';
		                }
		                ?>
		            </select>		            
				</p>
				
				<h3>Bildausrichtung (zum Text)</h3>
				<p>            
		            <select name="VALUE[3]" id="VALUE[3]">
		                <?php
		                foreach (array("links", "rechts", "oben") as $value) {
		                    echo '<option value="'.$value.'" ';
		                    
		                    if ("REX_VALUE[3]" == "$value") {
		                        echo 'selected="selected" ';
		                    }
		                    
		                    echo '>'.$value.' zum Text</option>';
		                }
		                ?>
		            </select>		        	
				</p>
				
				<h3>Branding der Bilder (Galerieansicht)</h3>
				<p>            
		            <select name="VALUE[4]" id="VALUE[4]">
		                <?php
		                foreach (array("Brand-Off", "Brand-On") as $value) {
		                    echo '<option value="'.$value.'" ';
		                    
		                    if ("REX_VALUE[4]" == "$value") {
		                        echo 'selected="selected" ';
		                    }
		                    
		                    echo '>'.$value.'</option>';
		                }
		                ?>
		            </select>
				</p>		            
				</div>
			</div>

			<h2 class="trigger"><a href="#">IMAGE (Title) (An/Aus)</a></h2>
			<div class="toggle_container">
				<div class="block">
				<h3>Bildtext (On/Off)</h3>
				<p>
		    		<select name="VALUE[6]" id="VALUE[6]">
		                <?php
		                foreach (array("Alt-Title-Off", "Alt-Title-On") as $value) {
		                    echo '<option value="'.$value.'" ';
		                    
		                    if ("REX_VALUE[6]" == "$value") {
		                        echo 'selected="selected" ';
		                    }
		                    
		                    echo '>'.$value.'</option>';
		                }
		                ?>
		            </select>
				</p>

		     	<h3>Bildtext (Eigener Title möglich)</h3>	        	
				<p>
					<input type="text" name="VALUE[7]" value="REX_VALUE[7]" size="30" />
				</p>
				
				<h3>Bildtext (Ausrichtung)</h3>
				<p>					
		            <select name="VALUE[8]" id="VALUE[8]">
		                <?php
		                foreach (array("Alt-Title-Bottom", "Alt-Title-Top") as $value) {
		                    echo '<option value="'.$value.'" ';
		                    
		                    if ("REX_VALUE[8]" == "$value") {
		                        echo 'selected="selected" ';
		                    }
		                    
		                    echo '>'.$value.'</option>';
		                }
		                ?>
		            </select>
		     	</p>		        				    
				</div>
			</div>

			<h2 class="trigger"><a href="#">FANCYBOX (Basics) (An/Aus)</a></h2>
			<div class="toggle_container">
				<div class="block">
				<h3>Galeriefunktion (On/Off)</h3>
				<p>
			   		<select name="VALUE[11]" id="VALUE[11]">
	                <?php
	                foreach (array("JS-On", "JS-Off") as $value) {
	                    echo '<option value="'.$value.'" ';
	                    
	                    if ("REX_VALUE[11]" == "$value") {
	                        echo 'selected="selected" ';
	                    }
	                    
	                    echo '>'.$value.'</option>';
	                }
	                ?>
			       	</select>
			   	</p>

				<h3>Galeriestyle</h3>          
				<p>
		            <select name="VALUE[12]" id="VALUE[12]">
		                <?php
		                foreach (array("Default", "Special-1", "Special-2", "Inline-1", "Inline-2") as $value) {
		                    echo '<option value="'.$value.'" ';
		                    
		                    if ("REX_VALUE[12]" == "$value") {
		                        echo 'selected="selected" ';
		                    }
		                    
		                    echo '>'.$value.'</option>';
		                }
		                ?>
		            </select>
		      	</p>		            

				<h3>Galeriegröße (Bild)</h3>
				<p>
		            <select name="VALUE[13]" id="VALUE[13]">
		                <?php
		                foreach (array("600", "800", "950", "1200") as $value) {
		                    echo '<option value="'.$value.'" ';
		                    
		                    if ("REX_VALUE[13]" == "$value") {
		                        echo 'selected="selected" ';
		                    }
		                    
		                    echo '>'.$value.'</option>';
		                }
		                ?>
		            </select>		            
				</p>
				</div>
			</div>

			<h2 class="trigger"><a href="#">FANCYBOX (Inline) (An/Aus)</a></h2>
			<div class="toggle_container">
				<div class="block">
				<h3>Website eingeben (Pop-Up)</h3>
				<p>
		        	<input type="text" name="VALUE[16]" value="REX_VALUE[16]" size="30" class="inp100"/>
		    	</p>
				<p>
					HINWEIS: <br>Nur nutzbar, wenn <br />a) Link (extern) und <br />b) JS-Style: Inline gewählt ist <br />- sonst reguläre Bildausgabe!
				</p>
				</div>		
			</div>
	
	</div>
<?php
	} 
	else 
	{
		echo rex_warning('Dieses Modul ben&ouml;tigt das "image_resize" OR "image_manager" Addon AND das "fancybox" Addon!');
	}
?>
