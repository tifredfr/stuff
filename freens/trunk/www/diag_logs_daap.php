#!/usr/local/bin/php
<?php
/*
	diag_logs_daap.php
	Copyright � 2008 Volker Theile (votdev@gmx.de)
	All rights reserved.

	part of FreeNAS (http://www.freenas.org)
	Copyright (C) 2005-2008 Olivier Cochard-Labb� <olivier@freenas.org>.
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice,
	   this list of conditions and the following disclaimer.

	2. Redistributions in binary form must reproduce the above copyright
	   notice, this list of conditions and the following disclaimer in the
	   documentation and/or other materials provided with the distribution.

	THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
	INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
	AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
	AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
	OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	POSSIBILITY OF SUCH DAMAGE.
*/
require("guiconfig.inc");
require("diag_logs.inc");

$pgtitle = array(gettext("Diagnostics"), gettext("Logs"), gettext("DAAP"));

$nentries = $config['syslogd']['nentries'];
if (!$nentries)
	$nentries = 50;

$logfile = "/var/log/mt-daapd.log";

if ($_POST['clear']) {
	exec("/bin/cat /dev/null > {$logfile}");
	header("Location: diag_logs_daap.php");
	exit;
}

if ($_POST['download']) {
	logs_download($logfile, "mt-daapd.log");
	exit;
}
?>
<?php include("fbegin.inc");?>
<table width="100%" border="0" cellpadding="0" cellspacing="0">
	<?php logs_display_menu("daap", $logmenu);?>
	<tr>
		<td class="tabcont">
			<form action="diag_logs_daap.php" method="post">
				<table width="100%" border="0" cellspacing="0" cellpadding="0">
					<tr>
						<td colspan="2" class="listtopic">
							<?php echo sprintf(gettext("Last %d %s log entries"), $nentries, gettext("DAAP"));?>
						</td>
					</tr>
					<?php logs_dump_ex($logfile, $nentries, 1, false);?>
				</table>
				<div id="submit">
					<input name="clear" type="submit" class="formbtn" value="<?=gettext("Clear");?>">
					<input name="download" type="submit" class="formbtn" value="<?=gettext("Download");?>">
				</div>
			</form>
		</td>
	</tr>
</table>
<?php include("fend.inc");?>