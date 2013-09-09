PRAGMA foreign_keys=OFF;
CREATE TABLE Migration ( "name" TEXT NOT NULL );
CREATE TABLE "Score" ( "question" TEXT NOT NULL, "score" REAL NOT NULL);
CREATE UNIQUE INDEX "question" on score (question ASC);
CREATE UNIQUE INDEX "name" on migration (name ASC);
