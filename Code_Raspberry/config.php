<?php
// Connect to database
    $server = "localhost";
    $user = "tung"; 
    $pass = "tunga239";
    $dbname = "robot_fish";

    $conn = mysqli_connect($server,$user,$pass,$dbname);

    // Check connection
    if($conn === false){
        die("ERROR: Could not connect. " . mysqli_connect_error());
    }
?>