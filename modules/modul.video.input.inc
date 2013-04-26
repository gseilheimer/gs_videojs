<?php
/**
 *=======================================================
 * modul: GS_VideoJS (jquery)
 * part: Eingabe
 * version: 1.0.6
 * redaxo Version: 4.5
 * redaxo AddOns: Image Manager & GS:FancyBox2 & GS:VideoJS
 * authored: www.contic.de, G. Seilheimer
 * date: 2013-04-26
 *=======================================================
 */

if( OOAddon::isAvailable('gs_videojs') )
{
   ?>
   <!--
   <script type="text/javascript">
      jQuery(function($)
      {
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
   -->

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
               echo "<p><img src=\"{$REX['HTDOCS_PATH']}/index.php?rex_img_type=fancybox_resize_200&rex_img_file={$rex_img}\" /><br />";
               echo "Bildtext: {$rex_img_txt} <br />Bildname: {$rex_img}</p>";
            }
            else
            {
               $rex_img = "file_dummy.gif";
               $rex_img_txt = $rex_img;
               echo "<p><img src=\"{$REX['HTDOCS_PATH']}redaxo/media/{$rex_img} \"><br />";
               echo "Bildtext: {$rex_img_txt} <br />Bildname: {$rex_img}</p>";
            }
            ?>

            <h3>Vorschau-Bild (Auswahl)</h3>
            <p>
               REX_MEDIA_BUTTON[1]
            </p>
            <h3>Video-MP4 (Auswahl)</h3>
            <p>
               REX_MEDIA_BUTTON[2]
            </p>

            <h3>Bildgroesse (in Pixel)</h3>
            <p>
               <select name="VALUE[2]" id="VALUE[2]">
                  <?php
                  foreach (array("100", "200", "300", "450", "600", "800", "950") as $value)
                  {
                     echo '<option value="'.$value.'" ';
                     if ("REX_VALUE[2]" == "$value")
                     {
                        echo 'selected="selected" ';
                     }
                     echo '>'.$value.'</option>';
                  }
                  ?>
               </select>
            </p>

            <h3>Bildformat (in n zu n)</h3>
            <p>
               <select name="VALUE[1]" id="VALUE[1]">
                  <?php
                  foreach (array("4-3", "16-10", "16-09") as $value)
                  {
                     echo '<option value="'.$value.'" ';
                     if ("REX_VALUE[1]" == "$value")
                     {
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
                  foreach (array("links", "rechts", "oben") as $value)
                  {
                     echo '<option value="'.$value.'" ';
                     if ("REX_VALUE[3]" == "$value")
                     {
                        echo 'selected="selected" ';
                     }
                     echo '>'.$value.' zum Text</option>';
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
                  foreach (array("Alt-Title-Off", "Alt-Title-On") as $value)
                  {
                     echo '<option value="'.$value.'" ';
                     if ("REX_VALUE[6]" == "$value")
                     {
                        echo 'selected="selected" ';
                     }
                     echo '>'.$value.'</option>';
                  }
                  ?>
               </select>
            </p>

            <h3>Bildtext (Eigener Title moeglich)</h3>
            <p>
               <input type="text" name="VALUE[7]" value="REX_VALUE[7]" size="30" />
            </p>

            <h3>Bildtext (Ausrichtung)</h3>
            <p>
               <select name="VALUE[8]" id="VALUE[8]">
                  <?php
                  foreach (array("Alt-Title-Bottom", "Alt-Title-Top") as $value)
                  {
                     echo '<option value="'.$value.'" ';
                     if ("REX_VALUE[8]" == "$value")
                     {
                        echo 'selected="selected" ';
                     }
                     echo '>'.$value.'</option>';
                  }
                  ?>
               </select>
            </p>
         </div>
      </div>

<?php
}
else
{
   echo rex_warning('Dieses Modul ben&ouml;tigt das "gs_videojs" Addon!');
}
?>