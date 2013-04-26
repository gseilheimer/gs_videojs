<?php
/**
 *=======================================================
 * modul: GS_VideoJS (jquery)
 * part: Ausgabe
 * version: 1.0.6
 * redaxo Version: 4.5
 * redaxo AddOns: Image Manager & GS:FancyBox2 & GS:VideoJS
 * authored: www.contic.de, G. Seilheimer
 * date: 2013-04-26
 *=======================================================
 */

// VARS
$error_text 				= "<span style='color: red'>HINWEIS: </span>";
$ok_img						= true;
$ok_txt						= true;
$ok_mp4                 = true;
$ok_img_error				= "Bild fehlt...!<br />";
$ok_mp4_error				= "Text fehlt...!<br />";
$ok_txt_error				= "Text fehlt...!<br />";

// VARS - Bild - Pfad
$rex_img 					= "REX_MEDIA[1]"; //bild pfad
$rex_mp4 					= "REX_MEDIA[2]"; //mp4 pfad

// VARS - Bild - Align, Size
$rex_mp4_form           = "REX_VALUE[1]"; // mp4 format
$rex_img_size				= "REX_VALUE[2]";	//bild groesse
$rex_img_align				= "REX_VALUE[3]";	//bild ausrichtung

// VARS - Bild - Title
$rex_img_txt_display	   = "REX_VALUE[6]";	//bild text on/off
$rex_img_txt            = "REX_VALUE[7]";	//bild text
$rex_img_txt_position	= "REX_VALUE[8]";	//bild text oben/unten

// VARS - Bild - JQuery
$rex_img_js					= "REX_VALUE[11]"; //bild js window aktiv
$rex_img_js_style			= "REX_VALUE[12]"; //bild js window style
$rex_img_size_window		= "REX_VALUE[13]"; //bild groesse window

// VARS - Link - JQuery
$rex_link_intern			= "REX_LINK[1]"; 	//artikel pfad
$rex_link_extern			= "REX_VALUE[16]"; //link extern pfad


// CHECK - Image
if("" == $rex_img)
{
   $ok_img	= false;
}
if("" == $rex_mp4)
{
   $ok_mp4	= false;
}

// CHECK - Image-Description
if("" == $rex_img_txt)
{
   $ok_txt	= false;
}

// CHECK - MP4-format-Description
if("" == $rex_img_txt)
{
   $ok_txt	= false;
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
$divclass_img			   = "<span {$style_float}>";	//innen
$divclass_img_end		   = "</span>"; //innen end


if(TRUE == $REX['REDAXO'])
{	//Ausgabe im Backend

   if(false == $ok_img)
   {
      echo $error_text . $ok_img_error;
   }

   if(false == $ok_mp4)
   {
      echo $error_text . $ok_mp4_error;
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

      echo "<br />{$rex_img_txt}<br />";
   }
   if("" != $rex_mp4)
   {

      echo "<video id=\"my_video-REX_ARTICLE_ID-REX_SLICE_ID\"
                     class=\"video-js vjs-default-skin\"
                     controls preload=\"auto\" width=\"{$rex_img_size}\" height=\"{$rex_img_size}\"
                     poster=\"{$REX['HTDOCS_PATH']}index.php?rex_img_type=fancybox_resize_{$rex_img_size}&rex_img_file={$rex_img}\"
                     data-setup=\"{}\" >";
      echo "<source src=\"{$REX['HTDOCS_PATH']}files/{$rex_mp4}\" type=\"video/mp4\">";
      echo "</video>";
   }

}	//Ausgabe im Backend - ENDE
else
{	//Ausgabe im Frontend

   if("" != $rex_img || "" != $rex_mp4)
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

      echo "{$divclass_img}";
      //Start - Image - DIV

         if("Alt-Title-Top" === $rex_img_txt_position && "Alt-Title-On" === $rex_img_txt_display)
         {
            echo "{$rex_img_txt}<br />";
         }


         echo "<video id=\"my_video-REX_ARTICLE_ID-REX_SLICE_ID\"
                  class=\"video-js vjs-default-skin\"
                  controls preload=\"auto\" width=\"{$rex_img_size}\" height=\"{$rex_img_size}\"
                  poster=\"{$REX['HTDOCS_PATH']}index.php?rex_img_type=fancybox_resize_{$rex_img_size}&rex_img_file={$rex_img}\"
                  data-setup=\"{}\" >";
         echo "<source src=\"{$REX['HTDOCS_PATH']}files/{$rex_mp4}\" type=\"video/mp4\">";
         echo "</video>";


         if("Alt-Title-Bottom" === $rex_img_txt_position && "Alt-Title-On" === $rex_img_txt_display)
         {
            echo "<br />{$rex_img_txt}";
         }

      echo "{$divclass_img_end}";
      //Start - Image - DIV
   }
}
?>