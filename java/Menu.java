package ru.schoolbolt;

import java.util.ArrayList;
import java.util.Scanner;

public class Menu extends MenuItem {
    private ArrayList<MenuItem> items;
    private boolean isSubmenu;

    private static Scanner scanner = new Scanner(System.in);

    public Menu() {
        super("");
        items = new ArrayList<>();
        isSubmenu = false;
    }

    private Menu(String title) {
        super(title);
        items = new ArrayList<>();
        isSubmenu = true;
    }

    /*public void addItem(MenuItem item) {
        items.add(item);
    }*/

    public SimpleMenuItem addItem(String title, Runnable action) {
        SimpleMenuItem item = new SimpleMenuItem(title, action);
        items.add(item);
        return item;
    }

    public Menu addSubmenu(String title) {
        Menu submenu = new Menu(title);
        items.add(submenu);
        return submenu;
    }

    @Override
    public void run() {
        boolean flag = true;
        while (flag) {
            printMenu();
            flag = handleUserInput();
        }
    }

    private void printMenu() {
        for (int i = 0; i < items.size(); i++) {
            System.out.println((i + 1) + ". " + items.get(i).getTitle());
        }
        System.out.println((items.size() + 1) + (isSubmenu ? ". Выход" : ". Назад"));
    }

    private boolean handleUserInput() {
        int x = scanner.nextInt();
        x--;

        if (x == items.size()) return false;

        if (x >= 0 && x < items.size()) {
            items.get(x).run();
        } else {
            System.out.println("Нет такого пункта");
        }

        return true;
    }
}
