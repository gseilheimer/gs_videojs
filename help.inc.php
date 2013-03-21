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
   // SUBPAGES
   //////////////////////////////////////////////////////////////////////////////////

?>

   <h3>Funktionen:</h3>
   <p>
      Addon zum Ausgaben von Video-Dateien in HTML5 und (x)HTML(4).<br />
      - in HTML5 mit dem VIDEO-TAGb<br />
      - in (x)HTML(4) mit Hilfe des JS-Skripts
   </p>

   <br />
   <h3>Benutzung:</h3>
   <p>
      Die JS-Dateien sind bereits im Addon VIDEOJS hinterlegt.<br />
      Jedes Video kann beliebige weitere Effekte erhalten, die auf das DIV angewendet werden koennen.<br />
      Zum einbinden des Video-Elements muss dazu der Typ class="video-js" im DIV notiert werden...
   </p>

   <br />
   <h3>Anwendungsbeispiel: VideoJS (jquery)</h3>
   <p>
      video id="my_video_1" class="video-js vjs-default-skin" <br />
        // controls
        controls preload="auto" width="640" height="264" <br />
        // preview image
        poster="my_video_poster.png"<br />
        data-setup="{}" <br />
        // sources
        source src="my_video.mp4" type='video/mp4'<br />
        source src="my_video.webm" type='video/webm'<br />
      /video
   </p>