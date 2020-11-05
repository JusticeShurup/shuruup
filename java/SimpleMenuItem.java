package ru.schoolbolt;

public class SimpleMenuItem extends MenuItem {
    private Runnable action;

    public SimpleMenuItem(String title, Runnable action) {
        super(title);
        this.action = action;
    }

    @Override
    public void run() {
        action.run();
    }
}
