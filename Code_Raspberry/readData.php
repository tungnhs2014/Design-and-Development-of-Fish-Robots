<?php
    header('Content-Type: application/json');

    // dang nhap vao database
    include("config.php");

    // Doc gia tri RGB tu database
    $sql = "select * from envData where id>(select max(id) from envData)-5";
    $result = mysqli_query($conn,$sql);

    $data = array();
    foreach ($result as $row){
        $data[] = $row;
    }

    mysqli_close($conn);
    echo json_encode($data);

?>