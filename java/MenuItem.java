package ru.schoolbolt;

public abstract class MenuItem {
    private String title;

    public MenuItem(String title) {
        this.title = title;
    }

    public abstract void run();

    public String getTitle() {
        return title;
    }
}
