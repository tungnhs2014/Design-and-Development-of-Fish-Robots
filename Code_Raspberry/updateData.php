<?php
// doc du lieu tu website gui ve;
$ontime   = $_POST["time1"];
$offtime  = $_POST["time2"];


// ket noi database
include("config.php");

//gui data xuong database
$sql  = "update settime set ontime='$ontime',offtime='$offtime'";

mysqli_query($conn, $sql);
// ngat ket noi voi database

mysqli_close($conn);
?>