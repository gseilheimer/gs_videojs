<?php

/**
 * VIDEOJS
 *
 * @author gilbert.seilheimer[at]contic[dot]de Gilbert Seilheimer
 * @author <a href="http://www.contic.de">www.contic.de</a>
 *
 * @package redaxo4
 * @version svn:$Id$
 */
/**
 * video-js Lib
 * @link https://github.com/zencoder/video-js
 * @version 3.x
 */

// AddOn-VIDEOJS

	//////////////////////////////////////////////////////////////////////////////////
	// CONFIG
	//////////////////////////////////////////////////////////////////////////////////

   // VARs
   $page = "gs_videojs";
   $page_root = $REX['INCLUDE_PATH'].'/addons/'.$page.'/';

   // VARs - ADDON
   $REX['ADDON']['name'][$page]          = 'VideoJS';
   $REX['ADDON']['rxid'][$page]          = '1052';
   $REX['ADDON']['page'][$page]          = $page;
   $REX['ADDON']['version'][$page]       = '0.9.5';
   $REX['ADDON']['author'][$page]        = 'Gilbert Seilheimer';
   $REX['ADDON']['supportpage'][$page]   = 'forum.redaxo.org';
   $REX['ADDON']['perm'][$page]          = $page.'[]';
   $REX['PERM'][]                        = $page.'[]';


   if( $REX['REDAXO'] && $REX['USER'] )
   {
      //////////////////////////////////////////////////////////////////////////////////
      // SUBPAGES
      //////////////////////////////////////////////////////////////////////////////////

      // Sprachdateien anhaengen
      $I18N->appendFile($REX['INCLUDE_PATH'].'/addons/'.$page.'/lang/');

      $REX['ADDON'][$page]['SUBPAGES'] =
         //        subpage,         label,                                       perm,   params, attributes
         array(
            array('',               $I18N->msg($page.'_subpage_index'),           '',     '',     ''),
            array('readme',         $I18N->msg($page.'_subpage_readme'),          '',     '',     ''),
            array('modul_video',    $I18N->msg($page.'_subpage_modul_video'),     '',     '',     ''),
         );

      //////////////////////////////////////////////////////////////////////////////////
      // INCLUDES
      //////////////////////////////////////////////////////////////////////////////////
      #require_once $addon_root.'.....inc.php';

   }
   else
   {

      //////////////////////////////////////////////////////////////////////////////////
      // FUNCTIONS
      //////////////////////////////////////////////////////////////////////////////////

      function gs_videojs_header( $params )
      {
         global $REX;

         if( FALSE == $REX["REDAXO"] )
         {
            $params['subject'] .= "\n  ".'<!-- GS:VIDEOJS-START -->';
            $params['subject'] .= "\n  ".'<!--[if lt IE 7]><html class="no-js ie6 oldie" lang=de><![endif]-->';
            $params['subject'] .= "\n  ".'<!--[if IE 7]><html class="no-js ie7 oldie" lang=de><![endif]-->';
            $params['subject'] .= "\n  ".'<!--[if IE 8]><html class="no-js ie8 oldie" lang=de><![endif]-->';
            $params['subject'] .= "\n  ".'<link rel="stylesheet" type="text/css" href="./files/addons/gs_videojs/video-js.min.css" media="screen, projection, print" />';
            $params['subject'] .= "\n  ".'<script type="text/javascript" src="./files/addons/gs_videojs/video-js.min.js"></script>';
            $params['subject'] .= "\n  ".'<!-- GS:VIDEOJS-ENDE -->';
         }
         return str_replace('</head>', '</head>', $params['subject']);
      }
      rex_register_extension('OUTPUT_FILTER', 'gs_videojs_header');

   }

?>