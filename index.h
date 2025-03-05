<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8" />
    <title>Image Switcher</title>
    <style type="text/css">
        body {
            margin: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            background-color: #f0f0f0;
            overflow: hidden; /* Prevent scrolling */
        }
        img {
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            object-fit: cover; /* Ensure the image covers the entire screen */
        }
        #message {
            position: absolute;
            color: white;
            font-size: 24px;
            font-family: Arial, sans-serif;
            z-index: 10; /* Make sure the text is above the image */
        }
    </style>
</head>
<body>
 <img id="image" src="https://assets.onecompiler.app/43av4tynn/43av4tdft/goat.jpeg" alt="Image" />
    <div id="message">Press Space to move</div>
    <script type="text/javascript">
        // List of image URLs
        const images = [
            'https://assets.onecompiler.app/43av4tynn/43av4tdft/goat.jpeg',
            'https://assets.onecompiler.app/43av4tynn/43av4tdft/dog.jpeg',
            'https://assets.onecompiler.app/43av4tynn/43av4tdft/cat.png',
            'https://assets.onecompiler.app/43av4tynn/43av4tdft/bird.jpeg',
            'https://assets.onecompiler.app/43av4tynn/43av4tdft/ship.jpeg'
        ];

        let currentIndex = 0; // Track the current image index

        // Function to change the image
        function changeImage() {
            // Increment the index and loop back to 0 when we reach the end
            currentIndex = (currentIndex + 1) % images.length;
            const imageElement = document.getElementById('image');
            imageElement.src = images[currentIndex]; // Set new image
        }
     // Listen for Space key press to change the image
        document.addEventListener('keydown', function(event) {
            if (event.code === 'Space') {
                changeImage();
            }
        });
    </script>

</body>
</html>
