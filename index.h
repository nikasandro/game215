<!DOCTYPE html>
<html>
<head>
    <script src="https://cdn.jsdelivr.net/npm/phaser@3.60.0/dist/phaser-arcade-physics.min.js"></script>
</head>
<body>

    <script>
			const config = {
				type: Phaser.AUTO,
				width: 800,
				height: 600,
				scene: {
					preload: preload,
					create: create,
					update: update
				},
				physics: {
					default: 'arcade',
					arcade: {
						gravity: { y: 300 }, // Set gravity in the y-direction
						debug: true // Enable debug mode to visualize physics bodies
					}
				}
			};

			const game = new Phaser.Game(config);

			let platforms;
			let player;

			function preload() {
				this.load.setBaseURL('https://labs.phaser.io');
				this.load.image('sky', 'assets/skies/space3.png');
				this.load.image('ground', 'assets/ground.png');
				this.load.spritesheet('dude', 'assets/dude.png', { frameWidth: 32, frameHeight: 48 });
			}

			function create() {
				// Add background
				this.add.image(400, 300, 'sky').setOrigin(0.5, 0.5);

				// Create platforms
				platforms = this.physics.add.staticGroup();
				platforms.create(400, 568, 'ground').setScale(2).refreshBody();

				// Create player
				player = this.physics.add.sprite(100, 450, 'dude');
				player.setBounce(0.2);
				player.setCollideWorldBounds(true);

				// Enable physics for player
				this.physics.add.collider(player, platforms);

				// Animation for player
				this.anims.create({
					key: 'left',
					frames: this.anims.generateFrameNumbers('dude', { start: 0, end: 3 }),
					frameRate: 10,
					repeat: -1
				});
				this.anims.create({
					key: 'turn',
					frames: [{ key: 'dude', frame: 4 }],
					frameRate: 20
				});
				this.anims.create({
					key: 'right',
					frames: this.anims.generateFrameNumbers('dude', { start: 5, end: 8 }),
					frameRate: 10,
					repeat: -1
				});

				// Enable keyboard input
				cursors = this.input.keyboard.createCursorKeys();
			}

			function update() {
				// Player movement
				if (cursors.left.isDown) {
					player.setVelocityX(-160);
					player.anims.play('left', true);
				} else if (cursors.right.isDown) {
					player.setVelocityX(160);
					player.anims.play('right', true);
				} else {
					player.setVelocityX(0);
					player.anims.play('turn');
				}

				// Jumping
				if (cursors.up.isDown && player.body.touching.down) {
					player.setVelocityY(-330);
				}
			}
		
	</script>

