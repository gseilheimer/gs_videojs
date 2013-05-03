#*********************************************
#
# INSTALLATION
#
# Autor: 	G.Seilheimer
# Company:	contic.de
# Version: 	0.9.6
# Update:	2013-05-03
# CMS:		Redaxo 4.5
#
#*********************************************


#*********************************************
#
# insert values into rex_template
#
#*********************************************

#INSERT IGNORE INTO `%TABLE_PREFIX%template` (`id`, `label`, `name`, `content`, `active`, `createuser`, `updateuser`, `createdate`, `updatedate`, `attributes`, `revision`)
#VALUES ('', '', 'gs : videojs (jquery)', '<!-- GS:VIDEOJS-START -->\r\n<!--[if lt IE 7]><html class=\"no-js ie6 oldie\" lang=de><![endif]-->\r\n<!--[if IE 7]><html class=\"no-js ie7 oldie\" lang=de><![endif]-->\r\n<!--[if IE 8]><html class=\"no-js ie8 oldie\" lang=de><![endif]-->\r\n<link rel=\"stylesheet\" type=\"text/css\" href=\"./files/addons/gs_videojs/video-js.min.css\" media=\"screen, projection, print\" />\r\n<script type=\"text/javascript\" src=\"./files/addons/gs_videojs/video-js.min.js\"></script>\r\n<!-- GS:VIDEOJS-ENDE -->', '0', 'gseilheimer', 'gseilheimer', '1364422766', '1364422766', 'a:3:{s:10:\"categories\";a:1:{s:3:\"all\";s:1:\"1\";}s:5:\"ctype\";a:0:{}s:7:\"modules\";a:1:{i:1;a:1:{s:3:\"all\";s:1:\"1\";}}}', '0')