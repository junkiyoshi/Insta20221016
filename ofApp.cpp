#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update() {

	this->mesh.clear();

	int radius_span = 5;
	int deg_span = 60;

	for (int deg = 0; deg < 360; deg += deg_span) {

		for (int radius = 30; radius < 600; radius += radius_span) {

			float circle_deg = deg + ofMap(radius, 30, 600, 0, 180);
			float next_ciecle_deg = deg + ofMap(radius + radius_span, 30, 600, 0, 180);

			this->mesh.addVertex(glm::vec3(radius * cos((circle_deg - deg_span * 0.2) * DEG_TO_RAD), radius * sin((circle_deg - deg_span * 0.2) * DEG_TO_RAD), 0));
			this->mesh.addVertex(glm::vec3(radius * cos((circle_deg + deg_span * 0.2) * DEG_TO_RAD), radius * sin((circle_deg + deg_span * 0.2) * DEG_TO_RAD), 0));
			this->mesh.addVertex(glm::vec3((radius + radius_span) * cos((next_ciecle_deg + deg_span * 0.2) * DEG_TO_RAD), (radius + radius_span) * sin((next_ciecle_deg + deg_span * 0.2) * DEG_TO_RAD), 0));
			this->mesh.addVertex(glm::vec3((radius + radius_span) * cos((next_ciecle_deg - deg_span * 0.2) * DEG_TO_RAD), (radius + radius_span) * sin((next_ciecle_deg - deg_span * 0.2) * DEG_TO_RAD), 0));

			this->mesh.addIndex(this->mesh.getNumVertices() - 1); this->mesh.addIndex(this->mesh.getNumVertices() - 2); this->mesh.addIndex(this->mesh.getNumVertices() - 3);
			this->mesh.addIndex(this->mesh.getNumVertices() - 1); this->mesh.addIndex(this->mesh.getNumVertices() - 3); this->mesh.addIndex(this->mesh.getNumVertices() - 4);

			ofColor color;
			color.setHsb(ofMap((radius + ofGetFrameNum() * 15) % 600, 0, 500, 0, 255), 130, 255);

			this->mesh.addColor(color); this->mesh.addColor(color); this->mesh.addColor(color); this->mesh.addColor(color);
		}
	}

	for (int deg = deg_span * 0.5; deg < 360 + deg_span; deg += deg_span) {

		for (int radius = 30; radius < 600; radius += radius_span) {

			float circle_deg = deg + ofMap(radius, 30, 600, 0, 180);
			float next_ciecle_deg = deg + ofMap(radius + radius_span, 30, 600, 0, 180);

			this->mesh.addVertex(glm::vec3(radius * cos((circle_deg - deg_span * 0.2) * DEG_TO_RAD), radius * sin((circle_deg - deg_span * 0.2) * DEG_TO_RAD), 0));
			this->mesh.addVertex(glm::vec3(radius * cos((circle_deg + deg_span * 0.2) * DEG_TO_RAD), radius * sin((circle_deg + deg_span * 0.2) * DEG_TO_RAD), 0));
			this->mesh.addVertex(glm::vec3((radius + radius_span) * cos((next_ciecle_deg + deg_span * 0.2) * DEG_TO_RAD), (radius + radius_span) * sin((next_ciecle_deg + deg_span * 0.2) * DEG_TO_RAD), 0));
			this->mesh.addVertex(glm::vec3((radius + radius_span) * cos((next_ciecle_deg - deg_span * 0.2) * DEG_TO_RAD), (radius + radius_span) * sin((next_ciecle_deg - deg_span * 0.2) * DEG_TO_RAD), 0));

			this->mesh.addIndex(this->mesh.getNumVertices() - 1); this->mesh.addIndex(this->mesh.getNumVertices() - 2); this->mesh.addIndex(this->mesh.getNumVertices() - 3);
			this->mesh.addIndex(this->mesh.getNumVertices() - 1); this->mesh.addIndex(this->mesh.getNumVertices() - 3); this->mesh.addIndex(this->mesh.getNumVertices() - 4);

			ofColor color;
			color.setHsb(ofMap(600 - (radius + ofGetFrameNum() * 15) % 500, 0, 500, 0, 255), 130, 255);

			this->mesh.addColor(color); this->mesh.addColor(color); this->mesh.addColor(color); this->mesh.addColor(color);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	this->mesh.draw();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}