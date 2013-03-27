#*********************************************
#
# UNINSTALLTION
#
# Autor: 	G.Seilheimer
# Company:	contic.de
# Version: 	0.9.5
# Update:	2013-03-27
# CMS:		Redaxo 4.4.1
#
#*********************************************


#*********************************************
#
# delete values from rex_template
#
#*********************************************

DELETE FROM `%TABLE_PREFIX%template` WHERE `name` LIKE '%gs : videojs (jquery)%' LIMIT 1;