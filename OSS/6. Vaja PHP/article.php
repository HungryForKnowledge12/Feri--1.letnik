<?php
include('database.php');
session_start();

if(!isset($_SESSION['username'])) {
    echo "Za ogled vsebine se morate prijaviti.";
    exit;
}

if(isset($_GET['id'])) {
    $id = $_GET['id'];
    $found = false;
    foreach($articles as $article) {
        if($article['id'] == $id) {
            echo "<h1>" . $article['title'] . "</h1>";
            echo "<p>" . $article['content'] . "</p>";
            $found = true;
            break;
        }
    }
    if(!$found) {
        echo "Novica ni najdena.";
    }
}
?>
