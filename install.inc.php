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

   // Installationsbedingungen pruefen
   $page_check_rex = '4.4.1';
   $page_check_php = 5;
   $page_check_addons = array('gs_markitup','textile');
   $page_check_status = true;

   //////////////////////////////////////////////////////////////////////////////////
   // CHECKS
   //////////////////////////////////////////////////////////////////////////////////

   // REX VERSION
   $page_check_rex = $REX['VERSION'].'.'.$REX['SUBVERSION'].'.'.$REX['MINORVERSION'] = "1";
   if(version_compare($page_check_rex, $page_check_rex, '<'))
   {
      $REX['ADDON']['installmsg'][$page] = 'Dieses Addon ben&ouml;tigt Redaxo Version '.$page_check_rex.' oder h&ouml;her.';
      $REX['ADDON']['install'][$page] = 0;
      $page_check_status = false;
   }

   // PHP VERSION
   if (intval(PHP_VERSION) < $page_check_php)
   {
      $REX['ADDON']['installmsg'][$page] = 'Dieses Addon ben&ouml;tigt mind. PHP '.$page_check_php.'!';
      $REX['ADDON']['install'][$page] = 0;
      $page_check_status = false;
   }

   // CHECK ADDONS
   foreach($page_check_addons as $a)
   {
      if (!OOAddon::isInstalled($a))
      {
         $REX['ADDON']['installmsg'][$page] = '<br />Addon "'.$a.'" ist nicht installiert.  >>> <a href="index.php?page=addon&addonname='.$a.'&install=1">jetzt installieren</a> <<<';
         $page_check_status = false;
      }
      else
      {
         if (!OOAddon::isAvailable($a))
         {
            $REX['ADDON']['installmsg'][$page] = '<br />Addon "'.$a.'" ist nicht aktiviert.  >>> <a href="index.php?page=addon&addonname='.$a.'&activate=1">jetzt aktivieren</a> <<<';
            $page_check_status = false;
         }
      }
   }

   //////////////////////////////////////////////////////////////////////////////////
   // DUMP
   //////////////////////////////////////////////////////////////////////////////////

   # $uninstall = dirname(__FILE__) . '/uninstall.sql';
   # rex_install_dump($uninstall);


   //////////////////////////////////////////////////////////////////////////////////
   // UPDATE/INSERT (DB)
   //////////////////////////////////////////////////////////////////////////////////

   $sql_table = $REX['TABLE_PREFIX']."template";

   $sql = rex_sql::factory();
   $sql->debugsql = 0; //Ausgabe Query
   $sql->setQuery("SELECT * FROM $sql_table WHERE name LIKE '%gs : videojs (jquery)%'");
   $sql_id = $sql->getValue('id');
   $sql->setTable($sql_table);

   if( $sql->getRows() )
   {
      $sql->setWhere('id = '.intval($sql_id));
      $sql->setValue("content", "<!-- GS:VIDEOJS-START -->\r\n<!--[if lt IE 7]><html class=\"no-js ie6 oldie\" lang=de><![endif]-->\r\n<!--[if IE 7]><html class=\"no-js ie7 oldie\" lang=de><![endif]-->\r\n<!--[if IE 8]><html class=\"no-js ie8 oldie\" lang=de><![endif]-->\r\n<link rel=\"stylesheet\" type=\"text/css\" href=\"./files/addons/gs_videojs/video-js.min.css\" media=\"screen, projection, print\" />\r\n<script type=\"text/javascript\" src=\"./files/addons/gs_videojs/video-js.min.js\"></script>\r\n<!-- GS:VIDEOJS-ENDE -->");
      $sql->update();
      if ( $sql->update() )
      {
         echo 'Zeile mit id '.intval($id).' erfolgreich aktuallisiert.';
      }
   }
   else
   {
      $sql->setValue("name", "gs : videojs (jquery)");
      $sql->setValue("content", "<!-- GS:VIDEOJS-START -->\r\n<!--[if lt IE 7]><html class=\"no-js ie6 oldie\" lang=de><![endif]-->\r\n<!--[if IE 7]><html class=\"no-js ie7 oldie\" lang=de><![endif]-->\r\n<!--[if IE 8]><html class=\"no-js ie8 oldie\" lang=de><![endif]-->\r\n<link rel=\"stylesheet\" type=\"text/css\" href=\"./files/addons/gs_videojs/video-js.min.css\" media=\"screen, projection, print\" />\r\n<script type=\"text/javascript\" src=\"./files/addons/gs_videojs/video-js.min.js\"></script>\r\n<!-- GS:VIDEOJS-ENDE -->");
      $sql->insert();
      if ( $sql->insert() )
      {
         echo 'Zeile mit id '.intval($id).' erfolgreich eingetragen.';
      }
   }

   //////////////////////////////////////////////////////////////////////////////////
   // INSTALL
   //////////////////////////////////////////////////////////////////////////////////
   if ($page_check_status)
   {
      $REX['ADDON']['install'][$page] = TRUE;
   }

?>