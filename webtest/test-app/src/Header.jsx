import './Header.css';
import logo from './assets/logo.svg';
import { useState } from 'react';
import { motion, AnimatePresence } from 'framer-motion';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faBars, faTimes } from '@fortawesome/free-solid-svg-icons';

function Header() {
  const [menuOpen, setMenuOpen] = useState(false);

  const toggleMenu = () => {
    setMenuOpen(!menuOpen);
  };

  return (
  <div className={`header ${menuOpen ? 'open' : ''}`}> 
      <nav className="headerNav">
        <div className="menu-holders">
          <img className="headerLogo" src={logo} alt="profile pic" />
          <div className="menu-icon" onClick={toggleMenu}>
            <FontAwesomeIcon
              icon={menuOpen ? faTimes : faBars}
              size="2x" // Adjust the size as needed
            />
          </div>
        </div>
        <AnimatePresence>
          {menuOpen && (
            <motion.ul
              initial={{ opacity: 0, y: -20 }}
              animate={{ opacity: 1, y: 0 }}
              exit={{ opacity: 0, y: -20 }}
              transition={{ duration: 0.5, delay: 0.2}}
              className="nav-links-mobile"
            >
              <li><a href="#">Ana Sayfa</a></li>
              <li><a href="#">Hakkimizda</a></li>
              <li><a href="#">Urunler</a></li>
              <li><a href="#">Siparis</a></li>
              <li><a href="#">Iletisim</a></li>
            </motion.ul>
          )}
        </AnimatePresence>
        <ul className="nav-links">
          <li><a href="#">Ana Sayfa</a></li>
          <li><a href="#">Hakkimizda</a></li>
          <li><a href="#">Urunler</a></li>
          <li><a href="#">Siparis</a></li>
          <li><a href="#">Iletisim</a></li>
        </ul>
      </nav>
    </div>
  );
}

export default Header;
