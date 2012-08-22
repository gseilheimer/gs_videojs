#*********************************************
#
# UNINSTALLATION
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
# delete values from rex_template
#
#*********************************************

DELETE FROM `%TABLE_PREFIX%template` WHERE `id`=1002 LIMIT 1;