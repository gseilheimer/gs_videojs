#*********************************************
#
# INSTALLATION
#
# Autor: 	G.Seilheimer
# Company:	contic.de
# Version: 	3.2
# Update:	2012-07-30
# CMS:		Redaxo 4.4
#
#*********************************************


#*********************************************
#
# insert values into rex_template
#
#*********************************************

INSERT IGNORE INTO `%TABLE_PREFIX%template` (`id`, `label`, `name`, `content`, `active`, `createuser`, `updateuser`, `createdate`, `updatedate`, `attributes`, `revision`) 
VALUES (1002, ' ', 'gs : video (jquery)', '<!-- ALL Flowplayer Tools -->\r\n<script type="text/javascript" src="./files/addons/gs_video/video-js.min.js"></script>', 0, 'gseilheimer', 'gseilheimer', 1284575671, 1284575671, 'a:3:{s:10:"categories";a:1:{s:3:"all";s:1:"1";}s:5:"ctype";a:0:{}s:7:"modules";a:1:{i:1;a:1:{s:3:"all";s:1:"1";}}}', 0);



#*********************************************
#
# alter values into rex_template
#
#*********************************************

ALTER TABLE `%TABLE_PREFIX%template` AUTO_INCREMENT=20;
