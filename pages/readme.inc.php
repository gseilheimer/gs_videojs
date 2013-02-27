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

	$msg = "Erfolgreich geladen...";
	
	if ($msg != '')
	{
		echo rex_info($msg);
	}

	// Sprachdateien anhaengen
	if(TRUE == $REX['REDAXO'])
	{
		$I18N->appendFile($REX['INCLUDE_PATH'].'/addons/'.$addon_name.'/lang/');
	}
	
	//////////////////////////////////////////////////////////////////////////////////
	// SUBPAGE
	//////////////////////////////////////////////////////////////////////////////////
?>

<div class="rex-addon-output">
	<h2 class="rex-hl2"><?php echo $I18N->msg('addon_subpage_readme_txt_01'); ?></h2>

	<div class="rex-addon-content">
		<p class="rex-code">
		<code><span style="color: #000000"> 
		<?php 
			echo $I18N->msg('addon_subpage_readme_txt_01_01') . "<br />";
			echo $I18N->msg('addon_subpage_readme_txt_01_02') . "<br />";
			echo $I18N->msg('addon_subpage_readme_txt_01_03') . "<br />";
		?>
		</span></code>
		</p>
	</div>	
</div>

<div class="rex-addon-output">
	<h2 class="rex-hl2"><?php echo $I18N->msg('addon_subpage_readme_txt_02'); ?></h2>

	<div class="rex-addon-content">
		<p class="rex-code">
		<code><span style="color: #000000"> 
		<?php 
			echo $I18N->msg('addon_subpage_readme_txt_02_01') . "<br />";
			echo $I18N->msg('addon_subpage_readme_txt_02_02') . "<br />";
			echo $I18N->msg('addon_subpage_readme_txt_02_03') . "<br />";
			echo $I18N->msg('addon_subpage_readme_txt_02_04') . "<br />";			
		?>
		</span></code>
		</p>
	</div>	
</div>

<div class="rex-addon-output">
	<h2 class="rex-hl2"><?php echo $I18N->msg('addon_subpage_readme_txt_03'); ?></h2>

	<div class="rex-addon-content">
		<p class="rex-code">
		<code><span style="color: #000000"> 
		<?php 
			echo $I18N->msg('addon_subpage_readme_txt_03_01') . "<br />";
			echo $I18N->msg('addon_subpage_readme_txt_03_02') . "<br />";
			echo $I18N->msg('addon_subpage_readme_txt_03_03') . "<br />";
			echo $I18N->msg('addon_subpage_readme_txt_03_04') . "<br />";
			echo $I18N->msg('addon_subpage_readme_txt_03_05') . "<br />";
		?>
		</span></code>
		</p>
	</div>	
</div>

<div class="rex-addon-output">
	<h2 class="rex-hl2"><?php echo $I18N->msg('addon_subpage_readme_txt_04'); ?></h2>

	<div class="rex-addon-content">
		<p class="rex-code">
		<code><span style="color: #000000"> 
		<?php 
			echo $I18N->msg('addon_subpage_readme_txt_04_01') . "<br />";
			echo $I18N->msg('addon_subpage_readme_txt_04_02') . "<br />";
			echo $I18N->msg('addon_subpage_readme_txt_04_03') . "<br />";
			echo $I18N->msg('addon_subpage_readme_txt_04_04') . "<br />";
			echo $I18N->msg('addon_subpage_readme_txt_04_05') . "<br />";
		?>
		</span></code>
		</p>
	</div>	
</div>