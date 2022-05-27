#include <SFML/Graphics.hpp>

using namespace sf;

void main(void) {
	//윈도우 창 생성
	RenderWindow app(VideoMode(520, 450), "BB");
	app.setFramerateLimit(60);

	Texture t1, t2, t3, t4;
	t1.loadFromFile("images/block01.png");
	t2.loadFromFile("images/background.jpg");
	t3.loadFromFile("images/ball.png");
	t4.loadFromFile("images/paddle.png");

	Sprite sBackground(t2), sBall(t3), spaddle(t4);
	spaddle.setPosition(300, 400);
	sBall.setPosition(300, 300);

	Sprite block[200];
	int n = 0;
	for (int x = 1; x <= 10; x++) {
		for (int y = 0; y <= 10; y++) {
			block[n].setTexture(t1);
			block[n].setPosition(x * 43, y * 20);
			n++;
		}
	}

	float dx = 3.0f, dy = 3.0f;


	while (app.isOpen()) {
		Event e;
		while (app.pollEvent(e)) {
			if (e.type == Event::Closed)
				app.close();
		}
		//공 움직이기
		sBall.move(dx, 0);
		sBall.move(0, dx);


		app.clear();
		app.draw(sBackground);
		app.draw(sBall);
		app.draw(spaddle);
		for (int i = 0; i < n; i++) {
			app.draw(block[i]);
		}
		app.display();
	}

}