<?php
function gentitle($title) {
	$navlevelsep = "|"; // Navigation level separator string.
	return join($navlevelsep, $title);
}

function genhtmltitle($title) {
	return system_get_hostname() . " - " . gentitle($title);
}

// Menu items.
// System
$menu['system']['desc'] = gettext("System");
$menu['system']['link'] = "";
$menu['system']['menuitem'] = array();
$menu['system']['menuitem'][] = array("desc" => gettext("General"), "link" => "system.php", "visible" => true);
$menu['system']['menuitem'][] = array("desc" => gettext("Advanced"), "link" => "system_advanced.php", "visible" => true);
$menu['system']['menuitem'][] = array("type" => "separator", "visible" => true);
if ("full" === $g['platform']) {
	$menu['system']['menuitem'][] = array("desc" => gettext("Packages"), "link" => "system_packages.php", "visible" => true);
} else {
	$menu['system']['menuitem'][] = array("desc" => gettext("Firmware"), "link" => "system_firmware.php", "visible" => true);
}
$menu['system']['menuitem'][] = array("desc" => gettext("Backup/Restore"), "link" => "system_backup.php", "visible" => true);
$menu['system']['menuitem'][] = array("desc" => gettext("Factory defaults"), "link" => "system_defaults.php", "visible" => true);
$menu['system']['menuitem'][] = array("type" => "separator", "visible" => true);
$menu['system']['menuitem'][] = array("desc" => gettext("Reboot"), "link" => "reboot.php", "visible" => true);
$menu['system']['menuitem'][] = array("desc" => gettext("Shutdown"), "link" => "shutdown.php", "visible" => true);

// Network
$menu['network']['desc'] = gettext("Network");
$menu['network']['link'] = "";
$menu['network']['menuitem'] = array();
$menu['network']['menuitem'][] = array("desc" => gettext("Interface Management"), "link" => "interfaces_assign.php", "visible" => true);
$menu['network']['menuitem'][] = array("desc" => "LAN", "link" => "interfaces_lan.php", "visible" => true);
for ($i = 1; isset($config['interfaces']['opt' . $i]); $i++) {
	$desc = $config['interfaces']['opt'.$i]['descr'];
	$menu['network']['menuitem'][] = array("desc" => "{$desc}", "link" => "interfaces_opt.php?index={$i}", "visible" => true);
}
$menu['network']['menuitem'][] = array("type" => "separator", "visible" => true);
$menu['network']['menuitem'][] = array("desc" => gettext("Hosts"), "link" => "system_hosts.php", "visible" => true);
$menu['network']['menuitem'][] = array("desc" => gettext("Static Routes"), "link" => "system_routes.php", "visible" => true);
$menu['network']['menuitem'][] = array("desc" => gettext("Firewall"), "link" => "system_firewall.php", "visible" => false);

// Firewall (MONOWALL)
$menu['firewall']['desc'] = gettext("Firewall");
$menu['firewall']['link'] = "";
$menu['firewall']['menuitem'] = array();
$menu['firewall']['menuitem'][] = array("desc" => gettext("Rules"), "link" => "firewall_rules.php", "visible" => true);
$menu['firewall']['menuitem'][] = array("desc" => gettext("NAT"), "link" => "firewall_nat.php", "visible" => true);
$menu['firewall']['menuitem'][] = array("desc" => gettext("Traffic shaper"), "link" => "firewall_shaper.php", "visible" => true);
$menu['firewall']['menuitem'][] = array("desc" => gettext("Aliases"), "link" => "firewall_aliases.php", "visible" => true);

// Disks
$menu['disks']['desc'] = gettext("Disks");
$menu['disks']['link'] = "";
$menu['disks']['menuitem'] = array();
$menu['disks']['menuitem'][] = array("desc" => gettext("Management"), "link" => "disks_manage.php", "visible" => true);
$menu['disks']['menuitem'][] = array("desc" => gettext("Software RAID"), "link" => "disks_raid_gmirror.php", "visible" => true);
$menu['disks']['menuitem'][] = array("desc" => gettext("Encryption"), "link" => "disks_crypt.php", "visible" => true);
$menu['disks']['menuitem'][] = array("desc" => gettext("Format"), "link" => "disks_init.php", "visible" => true);
$menu['disks']['menuitem'][] = array("desc" => gettext("Mount Point"), "link" => "disks_mount.php", "visible" => true);

// Services
$menu['services']['desc'] = gettext("Services");
$menu['services']['link'] = "services_status.php";
$menu['services']['menuitem'] = array();
$menu['services']['menuitem'][] = array("desc" => gettext("CIFS/SMB"), "link" => "services_samba.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("FTP"), "link" => "services_ftp.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("TFTP"), "link" => "services_tftp.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("SSH"), "link" => "services_sshd.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("NFS"), "link" => "services_nfs.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("AFP"), "link" => "services_afp.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("Rsync"), "link" => "services_rsyncd.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("Unison"), "link" => "services_unison.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("iSCSI Target"), "link" => "services_iscsitarget.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("UPnP"), "link" => "services_upnp.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("iTunes/DAAP"), "link" => "services_daap.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("Dynamic DNS"), "link" => "services_dynamicdns.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("SNMP"), "link" => "services_snmp.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("UPS"), "link" => "services_ups.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("Webserver"), "link" => "services_websrv.php", "visible" => false);
$menu['services']['menuitem'][] = array("desc" => gettext("BitTorrent"), "link" => "services_bittorrent.php", "visible" => true);
$menu['services']['menuitem'][] = array("type" => "separator", "visible" => true);

// Services (MONOWALL)
$menu['services']['menuitem'][] = array("type" => "separator", "visible" => true);
$menu['services']['menuitem'][]	= array("desc" => gettext("DNS forwarder"), "link" => "services_dnsmasq.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("Dynamic DNS"), "link" => "services_dyndns.php", "visible" => false);
$menu['services']['menuitem'][]	= array("desc" => gettext("DHCP server"), "link" => "services_dhcp.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("DHCP relay"), "link" => "services_dhcp_relay.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("Proxy ARP"), "link" => "services_proxyarp.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("Captive portal"), "link" => "services_captiveportal.php", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("Wake on LAN"), "link" => "services_wol.php", "visible" => true);
$menu['services']['menuitem'][] = array("type" => "separator", "visible" => true);
$menu['services']['menuitem'][] = array("desc" => gettext("Status"), "link" => "services_status.php", "visible" => true);

// Access
$menu['access']['desc'] = gettext("Access");
$menu['access']['link'] = "";
$menu['access']['menuitem'] = array();
$menu['access']['menuitem'][] = array("desc" => gettext("Users and Groups"), "link" => "access_users.php", "visible" => true);
$menu['access']['menuitem'][] = array("desc" => gettext("Active Directory"), "link" => "access_ad.php", "visible" => true);
$menu['access']['menuitem'][] = array("desc" => gettext("LDAP"), "link" => "access_ldap.php", "visible" => true);
$menu['access']['menuitem'][] = array("desc" => gettext("NIS"), "link" => "notavailable.php", "visible" => false);

// VPN (MONOWALL)
$menu['vpn']['desc'] = gettext("VPN");
$menu['vpn']['link'] = "";
$menu['vpn']['menuitem'] = array();
$menu['vpn']['menuitem'][]  				= array("desc" => gettext("IPsec"), "link" => "vpn_ipsec.php", "visible" => true);
$menu['vpn']['menuitem'][] 				= array("desc" => gettext("PPTP"), "link" => "vpn_pptp.php", "visible" => true);

// Status
$menu['status']['desc'] = gettext("Status");
$menu['status']['link'] = "index.php";
$menu['status']['menuitem'] = array();
$menu['status']['menuitem'][] = array("desc" => gettext("System"), "link" => "index.php", "visible" => true);
$menu['status']['menuitem'][] = array("desc" => gettext("Process"), "link" => "status_process.php", "visible" => true);
$menu['status']['menuitem'][] = array("type" => "separator", "visible" => true);
$menu['status']['menuitem'][] = array("desc" => gettext("Interfaces"), "link" => "status_interfaces.php", "visible" => true);
$menu['status']['menuitem'][] = array("desc" => gettext("Wireless"), "link" => "status_wireless.php", "visible" => false);
$menu['status']['menuitem'][] = array("type" => "separator", "visible" => true);
$menu['status']['menuitem'][] = array("desc" => gettext("Disks"), "link" => "status_disks.php", "visible" => true);
$menu['status']['menuitem'][] = array("desc" => gettext("Graph"), "link" => "status_graph.php", "visible" => true);
$menu['status']['menuitem'][] = array("type" => "separator", "visible" => true);
$menu['status']['menuitem'][] = array("desc" => gettext("Email Report"), "link" => "status_report.php", "visible" => true);
if (isset($config['captiveportal']['enable'])) {
	$menu['status']['menuitem'][]	= array("desc" => gettext("Captive Portal"), "link" => "status_captiveportal.php", "visible" => true);
}

// Advanced
$menu['advanced']['desc'] = gettext("Advanced");
$menu['advanced']['link'] = "";
$menu['advanced']['menuitem'] = array();
$menu['advanced']['menuitem'][] = array("desc" => gettext("File Editor"), "link" => "system_edit.php", "visible" => true);
$menu['advanced']['menuitem'][] = array("desc" => gettext("File Manager"), "link" => "quixplorer", "visible" => true, "target" => "_blank");
$menu['advanced']['menuitem'][] = array("type" => "separator", "visible" => true);
$menu['advanced']['menuitem'][] = array("desc" => gettext("Command"), "link" => "exec.php", "visible" => true);

// Diagnostics
$menu['diagnostics']['desc'] = gettext("Diagnostics");
$menu['diagnostics']['link'] = "";
$menu['diagnostics']['menuitem'] = array();
$menu['diagnostics']['menuitem'][] = array("desc" => gettext("Logs"), "link" => "diag_logs.php", "visible" => true);
$menu['diagnostics']['menuitem'][] = array("desc" => gettext("Information"), "link" => "diag_infos.php", "visible" => true);
$menu['diagnostics']['menuitem'][] = array("type" => "separator", "visible" => true);
$menu['diagnostics']['menuitem'][] = array("desc" => gettext("Ping/Traceroute"), "link" => "diag_ping.php", "visible" => true);
$menu['diagnostics']['menuitem'][] = array("desc" => gettext("ARP Tables"), "link" => "diag_arp.php", "visible" => true);
$menu['diagnostics']['menuitem'][] = array("desc" => gettext("Routes"), "link" => "diag_routes.php", "visible" => true);
$menu['diagnostics']['menuitem'][] = array("type" => "separator", "visible" => true);
$menu['diagnostics']['menuitem'][] = array("desc" => gettext("DHCP Leases"), "link" => "diag_dhcp_leases.php", "visible" => true);
$menu['diagnostics']['menuitem'][] = array("desc" => gettext("IPsec"), "link" => "diag_ipsec_sad.php", "visible" => true);
$menu['diagnostics']['menuitem'][] = array("desc" => gettext("Firewall states"), "link" => "diag_ipfstat.php", "visible" => true);


// Help
$menu['help']['desc'] = gettext("Help");
$menu['help']['link'] = "";
$menu['help']['menuitem'] = array();
$menu['help']['menuitem'][] = array("desc" => gettext("WebSite"), "link" => "http://overlays.thelinuxfr.org/projects/show/freens", "visible" => true, "target" => "_blank");
$menu['help']['menuitem'][] = array("desc" => gettext("Wiki"), "link" => "http://overlays.thelinuxfr.org/wiki/freens", "visible" => true, "target" => "_blank");
$menu['help']['menuitem'][] = array("desc" => gettext("Forum"), "link" => "http://overlays.thelinuxfr.org/projects/freens/boards", "visible" => true, "target" => "_blank");
$menu['help']['menuitem'][] = array("type" => "separator", "visible" => true);
$menu['help']['menuitem'][] = array("desc" => gettext("Release notes"), "link" => "changes.php", "visible" => true);
$menu['help']['menuitem'][] = array("desc" => gettext("License & Credits"), "link" => "license.php", "visible" => true);

function display_menu($menuid) {
	global $menu;

	echo "<li>\n";
	echo "	<a href=\"{$menu[$menuid]['link']}\" onmouseover=\"mopen('{$menuid}')\" onmouseout=\"mclosetime()\">{$menu[$menuid]['desc']}</a>\n";
	echo "	<div id=\"{$menuid}\" onmouseover=\"mcancelclosetime()\" onmouseout=\"mclosetime()\">\n";

	# Display menu items.
	foreach ($menu[$menuid]['menuitem'] as $menuk => $menuv) {
		# Is menu item visible?
		if (!$menuv['visible']) {
			continue;
		}
		if ("separator" !== $menuv['type']) {
			# Display menuitem.
			echo "<a href=\"{$menuv['link']}\" target=\"{$menuv['target']}\" title=\"{$menuv['desc']}\">{$menuv['desc']}</a>\n";
		} else {
			# Display separator.
			echo "<span class=\"tabseparator\">&nbsp;</span>";
		}
	}

	echo "	</div>\n";
	echo "</li>\n";
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
	<title><?=genhtmltitle($pgtitle);?></title>
	<meta http-equiv="Content-Type" content="text/html; charset=<?=system_get_language_codeset();?>"/>
	<?php if ($pgrefresh):?>
	<meta http-equiv="refresh" content="<?=$pgrefresh;?>"/>
	<?php endif;?>
	<link href="gui.css" rel="stylesheet" type="text/css"/>
	<link href="navbar.css" rel="stylesheet" type="text/css"/>
	<link href="tabs.css" rel="stylesheet" type="text/css"/>
	<script type="text/javascript" src="javascript/gui.js"></script>
	<script type="text/javascript" src="javascript/navbar.js"></script>
</head>
<body>
<div id="header">
	<div id="headerlogo">
		<a title="www.<?=get_product_url();?>" href="http://<?=get_product_url();?>" target="_blank"><img src="/header_logo.png" alt="logo"/></a>
	</div>
	<div id="headerrlogo">
		<div class="hostname">
			<span><?=system_get_hostname();?>&nbsp;</span>
		</div>
	</div>
</div>
<div id="headernavbar">
	<ul id="navbarmenu">
		<?=display_menu("system");?>
		<?=display_menu("network");?>
		<?=display_menu("firewall");?>
		<?=display_menu("disks");?>
		<?=display_menu("services");?>
		<!-- Begin extension section -->
		<?php if (is_dir("{$g['www_path']}/ext")):?>
		<li>
			<a href="" onmouseover="mopen('extensions')" onmouseout="mclosetime()"><?=gettext("Extensions");?></a>
			<div id="extensions" onmouseover="mcancelclosetime()" onmouseout="mclosetime()">
				<?php
				$dh = @opendir("{$g['www_path']}/ext");
				if ($dh) {
					while (($extd = readdir($dh)) !== false) {
						if (($extd === ".") || ($extd === ".."))
							continue;
						@include("{$g['www_path']}/ext/" . $extd . "/menu.inc");
					}
					closedir($dh);
				}?>
			</div>
		</li>
		<?php endif;?>
		<!-- End extension section -->
		<?=display_menu("access");?>
		<?=display_menu("vpn");?>
		<?=display_menu("status");?>
		<?=display_menu("diagnostics");?>
		<?=display_menu("advanced");?>
		<?=display_menu("help");?>
	</ul>
	<div style="clear:both"></div>
</div>
<div id="pagecontent">
	<table width="100%" border="0" cellspacing="0" cellpadding="2">
	  <tr valign="top">
	    <td>
				<table width="100%" border="0" cellpadding="10" cellspacing="0">
	        <tr>
						<td>
							<?php if (!$pgtitle_omit): ?>
	      			<p class="pgtitle"><?=gentitle($pgtitle);?></p>
							<?php endif;?>