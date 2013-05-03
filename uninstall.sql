#*********************************************
#
# UNINSTALLTION
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
# delete values from rex_template
#
#*********************************************

DELETE FROM `%TABLE_PREFIX%template` WHERE `name` LIKE '%gs : videojs (jquery)%' LIMIT 1;