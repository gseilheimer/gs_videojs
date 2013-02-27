<?php

 /** 
 * VIDEO-JS
 *
 * @author gilbert.seilheimer@contic.de
 *
 * @package redaxo4
 * @version svn:$Id$
 */

// AddOn-VIDEO-JS

	//////////////////////////////////////////////////////////////////////////////////
	// CONFIG
	//////////////////////////////////////////////////////////////////////////////////

	// VARs
	$addon_name = "gs_videojs";

	// Sprachdateien anhaengen
	if(TRUE == $REX['REDAXO'])
	{
		$I18N->appendFile($REX['INCLUDE_PATH'].'/addons/'.$addon_name.'/lang/');
	}
			
	$REX['ADDON']['rxid'][$addon_name] 			= '1002';
	$REX['ADDON']['page'][$addon_name] 			= "video-js";
	
	if(TRUE == $REX['REDAXO'])
	{
		$REX['ADDON']['name'][$addon_name] 		= $I18N->msg("addon_name");
	}
	
	// Recht um das AddOn fuer�¼berhaupt einsehen zu koennen
	$REX['ADDON']['perm'][$addon_name] 			= 'video-js[1]';
	
	// Credits
	$REX['ADDON']['version'][$addon_name] 		= '3.2';
	$REX['ADDON']['author'][$addon_name] 		= 'Gilbert Seilheimer';
	$REX['ADDON']['supportpage'][$addon_name] 	= 'forum.redaxo.org';
	
	// *************
	$REX['PERM'][] = 'video-js[1]';
	$REX['PERM'][] = 'video-js[2]';
	
	// FÃƒÆ’Ã‚Â¼r Benutzervewaltung
	$REX['EXTPERM'][] = 'video-js[3]';

	//////////////////////////////////////////////////////////////////////////////////
	// SUBPAGES
	//////////////////////////////////////////////////////////////////////////////////
	
	if(TRUE == $REX['REDAXO'])
	{
		$REX['ADDON'][$addon_name]['SUBPAGES'] = 
		array(
			  array('readme', $I18N->msg('addon_subpage_readme')),
			  array('textile_video', $I18N->msg('addon_subpage_textile_video')),
		);
	}
?>